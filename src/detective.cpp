#include <eosiolib/eosio.hpp>
#include <eosiolib/time.hpp>
#include <string>

namespace eosio {
  using std::string;

  class [[eosio::contract("detective")]] forum : public contract {
      public:
          detective(name receiver, name code, datastream<const char*> ds)
          :eosio::contract(receiver, code, ds)
          {}

          [[eosio::action]]
          void post(name account) {
          }

          [[eosio::action]]
          void expire(name account) {
          }

      private:
          struct [[eosio::table]] account_row {
             name         account;    //account name
             uint8_t      score;      //enables a score between 0 to 255
             string       metadata;   //json meta data
             time_point   timestamp;

             uint64_t primary_key()const { return account.value(); }
             uint64_t by_timestamp() const { return uint64_t(timestamp.sec_since_epoch()); }
          };
          typedef eosio::multi_index<
            name("accounts"), account_row,
            indexed_by<name("bytime"), const_mem_fun<account_row, uint64_t, &account_row::by_timestamp>>
          > accounts;

  };
}

EOSIO_DISPATCH(detective, (post)(expire))
