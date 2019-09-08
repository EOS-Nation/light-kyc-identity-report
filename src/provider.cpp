void identity::provider( const eosio::name name, const string metadata )
{
    check( is_account( name ), "provider account does not exist");

    auto provider_itr = _provider.find( name.value );

    // modify existing provider
    if ( provider_itr != _provider.end()) {
        check( has_auth( name ) || has_auth( get_self() ), "missing required authority");

        _provider.modify( provider_itr, get_self(), [&]( auto & row ) {
            row.metadata    = metadata;
        });
    // add provider
    } else {
        require_auth( get_self() );

        _provider.emplace( get_self(), [&]( auto & row ) {
            row.name        = name;
            row.metadata    = metadata;
        });
    }
}
