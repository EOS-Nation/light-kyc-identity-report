#include <eosio/eosio.hpp>
#include <eosio/system.hpp>
#include <eosio/crypto.hpp>

#include "get_trx_id.hpp"

#include <string>

using namespace eosio;
using namespace std;

class [[eosio::contract("identity")]] identity : public contract {
public:
    using contract::contract;

    /**
     * Construct a new contract given the contract name
     *
     * @param {name} receiver - The name of this contract
     * @param {name} code - The code name of the action this contract is processing.
     * @param {datastream} ds - The datastream used
     */
    identity( name receiver, name code, eosio::datastream<const char*> ds )
        : contract( receiver, code, ds ),
            _tier( get_self(), get_self().value ),
            _identity( get_self(), get_self().value )
    {}

    /**
     * ACTION `add`
     *
     * Add identity report to the smart contract table
     *
     * - Authority: `get_self()`
     *
     * @param {name} account - identity account name
     * @param {public_key} key - public key that was used to sign the proof of identity
     * @param {uint8_t} tier - identity tier assosiated with identity report
     * @param {string} metadata - additional metadata about report
     *
     * @example
     *
     * cleos push action identity add '["myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "Additional Metadata"]' -p identity
     */
    [[eosio::action]]
    void add( const eosio::name account,
              const eosio::public_key key,
              const uint8_t tier,
              const string metadata );

    /**
     * ACTION `remove`
     *
     * Remove identity report from the smart contract table
     *
     * - Authority: `get_self()`
     *
     * @param {name} account - identity account name
     *
     * @example
     *
     * cleos push action identity remove '["myaccount"]' -p identity
     */
    [[eosio::action]]
    void remove( const eosio::name account );

    /**
     * ACTION `tier`
     *
     * Add metadata for tier
     *
     * - Authority: `get_self()`
     *
     * @param {uint8_t} tier - identity tier
     * @param {name} name - identity tier name
     * @param {string} metadata - identity tier metadata
     * @example
     *
     * cleos push action identity tier '[1, "standard", "Standard Tier"]' -p identity
     */
    [[eosio::action]]
    void tier( const uint8_t tier, const eosio::name name, const string metadata );

    /**
     * ACTION `clean`
     *
     * removes all rows from existing tables
     *
     * - Authority: `get_self()`
     */
    [[eosio::action]]
    void clean();

    using add_action = eosio::action_wrapper<"add"_n, &identity::add>;
    using remove_action = eosio::action_wrapper<"remove"_n, &identity::remove>;
    using tier_action = eosio::action_wrapper<"tier"_n, &identity::tier>;

private:
    /**
     * TABLE `identity`
     *
     * @param {name} name - identity account name
     * @param {public_key} key - public key that was used to sign the proof of identity
     * @param {uint8_t} tier - identity tier assosiated with identity report
     * @param {string} metadata - additional metadata about report
     * @param {checksum256} trx_id - identity creation transaction id
     * @param {time_point_sec} timestamp - identity creation timestamp
     *
     * @example
     *
     * {
     *   "name": "myaccount",
     *   "key": "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV",
     *   "tier": 1,
     *   "metadata": "Additional Metadata",
     *   "trx_id": "f0889d11501fc83ff52d8af62e2d1552193c728e874d9bb559f30a0012deee3e",
     *   "timestamp": "2019-09-09T00:00:00"
     * }
     */
    struct [[eosio::table("identity")]] identity_row {
        eosio::name             name;
        eosio::public_key       key;
        uint8_t                 tier;
        string                  metadata;
        checksum256             trx_id;
        time_point_sec          timestamp;

        uint64_t primary_key() const { return name.value; }
    };

    /**
     * ## TABLE `tier`
     *
     * @param {uint8_t} tier - identity tier
     * @param {name} name - identity tier name
     * @param {string} metadata - identity tier metadata
     *
     * @example
     *
     * {
     *   "tier": 1,
     *   "name": "standard",
     *   "metadata": "Standard Tier"
     * }
     */
    struct [[eosio::table("tier")]] tier_row {
        uint8_t             tier;
        eosio::name         name;
        string              metadata;

        uint64_t primary_key() const { return tier; }
    };

    // Tables
    typedef multi_index<"identity"_n, identity_row> identity_table;
    typedef multi_index<"tier"_n, tier_row> tier_table;

    // local instances of the multi indexes
    tier_table          _tier;
    identity_table      _identity;

    // private helpers
    // ===============
};