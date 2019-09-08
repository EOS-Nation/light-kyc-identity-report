void identity::tier( const uint8_t tier, const eosio::name name, const string metadata )
{
    require_auth( get_self() );

    check( name.length() > 0, "tier name must have at least 1 character");
    auto tier_itr = _tier.find( tier );

    // modify existing tier
    if ( tier_itr != _tier.end()) {
        _tier.modify( tier_itr, get_self(), [&]( auto & row ) {
            row.name        = name;
            row.metadata    = metadata;
        });
    // add tier
    } else {
        _tier.emplace( get_self(), [&]( auto & row ) {
            row.tier        = tier;
            row.name        = name;
            row.metadata    = metadata;
        });
    }
}
