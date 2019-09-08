void identity::clean()
{
    require_auth( get_self() );

    // TO-DO remove identity scopes

    auto tier_itr = _tier.begin();
    while ( tier_itr != _tier.end() ) {
        tier_itr = _tier.erase(tier_itr);
    }

    auto provider_itr = _provider.begin();
    while ( provider_itr != _provider.end() ) {
        provider_itr = _provider.erase(provider_itr);
    }
}