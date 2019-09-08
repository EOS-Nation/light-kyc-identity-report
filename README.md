# Light KYC Identity Report - EOSIO Smart Contracts

## ACTION

- [`add`](#action-add)
- [`remove`](#action-remove)
- [`tier`](#action-tier)
- [`provider`](#action-provider)

## TABLE

- [`accounts`](#accounts-table)
- [`tier`](#tier-table)
- [`provider`](#provider-table)

## ACTION `add`

Add light KYC identity report to the smart contract table

Authority: `provider`

### params

- `{name} provider` - light kyc provider account
- `{name} name` - identity account
- `{public_key} key` - public key that was used to sign the proof of identity
- `{uint8_t} tier` - identity tier assosiated with identity report
- `{string} metadata` - additional metadata about report

### example

```bash
cleos push action identity add '["myprovider", "myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "Additional Metadata for Light KYC"]' -p myprovider
```

## ACTION `remove`

Remove light KYC identity report from the smart contract table

- Authority: `provider`

### params

- `{name} provider` - light kyc provider account
- `{name} name` - identity account

### example

```bash
cleos push action identity remove '["myprovider", "myaccount"]' -p myprovider
```

## ACTION `tier`

Add metadata for tier

- Authority: `get_self()`

### params

- `{uint8_t} tier` - identity tier
- `{name} name` - identity tier name
- `{string} metadata` - identity tier metadata

### example

```bash
cleos push action identity tier '[1, "standard", "Standard Tier for light KYC"]' -p identity
```

## ACTION `provider`

Add authorized light kyc provider

- Authority: `get_self()`

### params

- `{name} provider` - light kyc provider account

### example

```bash
cleos push action identity provider '["myprovider"]' -p identity
```

## TABLE `account`

- Scope: `provider`

- `{name} name` - identity account
- `{public_key} key` - public key that was used to sign the proof of identity
- `{uint8_t} tier` - identity tier assosiated with identity report
- `{string} metadata` - additional metadata about report

### example

```json
{
  "name": "myaccount",
  "key": "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV",
  "tier": 1,
  "metadata": "Additional Metadata for Light KYC"
}
```

## TABLE `provider`

- `{name} provider` - light kyc provider account

### example

```json
{
  "name": "myprovider"
}
```

## TABLE `tier`

- `{uint8_t} tier` - identity tier
- `{name} name` - identity tier name
- `{string} metadata` - identity tier metadata

### example

```json
{
  "tier": 1,
  "name": "standard",
  "metadata": "Standard Tier for light KYC"
}
```
