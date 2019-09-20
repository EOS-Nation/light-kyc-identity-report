#!/usr/bin/env bash

# ACTIONS
# =======
# add tier
cleos push action identity tier '[1, "standard", "Standard Tier"]' -p identity

# add/remove identity using provider
cleos push action identity add '["myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "remove me"]' -p identity
cleos push action identity remove '["myaccount"]' -p identity
cleos push action identity add '["myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "Additional Metadata"]' -p identity

# ERRORS
# ======
# missing authority of identity
cleos push action identity add '["myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "not authorized"]' -p myaccount

# missing authority of identity
cleos push action identity tier '[1, "standard", "missing authority of identity"]' -p myaccount

# assertion failure with message: tier does not exist
cleos push action identity add '["myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 9, "tier does not exist"]' -p identity

# # clean
# cleos push action identity clean '[""]' -p identity

# TABLES
# ======
# identity
cleos get table identity identity identity | jq .rows[0]

# tier
cleos get table identity identity tier | jq .rows[0]