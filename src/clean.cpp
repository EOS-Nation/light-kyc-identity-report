void identity::clean()
{
    require_auth( get_self() );

    // get identity scoped by provider
    auto provider_itr = _provider.begin();
    while ( provider_itr != _provider.end() ) {
        identity_table _identity( get_self(), provider_itr->name.value );
        auto identity_itr = _identity.begin();

        // identity
        while ( identity_itr != _identity.end() ) {
            identity_itr = _identity.erase(identity_itr);
        }

        // provider
        provider_itr = _provider.erase(provider_itr);
    }

    // tier
    auto tier_itr = _tier.begin();
    while ( tier_itr != _tier.end() ) {
        tier_itr = _tier.erase(tier_itr);
    }
}