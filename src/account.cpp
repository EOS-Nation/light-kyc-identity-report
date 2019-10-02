void identity::add( const eosio::name account,
                    const eosio::public_key key,
                    const uint8_t tier,
                    const string metadata )
{
    // validation
    require_auth( get_self() );
    // check( is_account( account ), "account does not exist");
    check( _tier.find( tier ) != _tier.end(), "tier does not exist");

    // scoped identity table
    auto identity_itr = _identity.find( account.value );

    // modify existing identity
    if ( identity_itr != _identity.end()) {
        _identity.modify( identity_itr, get_self(), [&]( auto & row ) {
            row.key = key;
            row.tier = tier;
            row.metadata = metadata;
            row.trx_id = get_trx_id();
            row.timestamp = current_time_point();
        });
    // add identity
    } else {
        _identity.emplace( get_self(), [&]( auto & row ) {
            row.name = account;
            row.key = key;
            row.tier = tier;
            row.metadata = metadata;
            row.trx_id = get_trx_id();
            row.timestamp = current_time_point();
        });
    }
}

void identity::remove( const eosio::name account )
{
    require_auth( get_self() );

    auto identity_itr = _identity.find( account.value );
    check( identity_itr != _identity.end(), "account does not exist");

    _identity.erase( identity_itr );
}