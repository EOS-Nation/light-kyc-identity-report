# Light KYC Identity Report - EOSIO Smart Contracts

## ACTION

- [`add`](#action-add)
- [`remove`](#action-remove)
- [`tier`](#action-tier)
- [`provider`](#action-provider)

## TABLE

- [`identity`](#identity-table)
- [`tier`](#tier-table)
- [`provider`](#provider-table)

## ACTION `add`

Add identity report to the smart contract table

- Authority: `provider`

### params

- `{name} provider` - provider account name
- `{name} account` - identity account name
- `{public_key} key` - public key that was used to sign the proof of identity
- `{uint8_t} tier` - identity tier assosiated with identity report
- `{string} metadata` - additional metadata about report

### example

```bash
cleos push action identity add '["myprovider", "myaccount", "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV", 1, "Additional Metadata"]' -p myprovider
```

## ACTION `remove`

Remove identity report from the smart contract table

- Authority: `provider`

### params

- `{name} provider` - provider account name
- `{name} account` - identity account name

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
cleos push action identity tier '[1, "standard", "Standard Tier"]' -p identity
```

## ACTION `provider`

Add authorized provider

- Authority: `get_self()` (if does not exist)
- Authority: `provider` or `get_self()` (if already exist)

### params

- `{name} name` - provider account name
- `{string} metadata` - provider metadata

### example

```bash
cleos push action identity provider '["myprovider", "Provider Metadata"]' -p identity
```

## TABLE `identity`

- Scope: `provider`

### params

- `{name} name` - identity account name
- `{public_key} key` - public key that was used to sign the proof of identity
- `{uint8_t} tier` - identity tier assosiated with identity report
- `{string} metadata` - additional metadata about report
- `{checksum256} trx_id` - identity creation transaction id
- `{time_point_sec} timestamp` - identity creation timestamp

### example

```json
{
  "name": "myaccount",
  "key": "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV",
  "tier": 1,
  "metadata": "Additional Metadata",
  "trx_id": "f0889d11501fc83ff52d8af62e2d1552193c728e874d9bb559f30a0012deee3e",
  "timestamp": "2019-09-09T00:00:00"
}
```

## TABLE `provider`

### params

- `{name} provider` - provider account name
- `{string} metadata` - provider metadata

### example

```json
{
  "name": "myprovider",
  "metadata": "Provider Metadata"
}
```

## TABLE `tier`

### params

- `{uint8_t} tier` - identity tier
- `{name} name` - identity tier name
- `{string} metadata` - identity tier metadata

### example

```json
{
  "tier": 1,
  "name": "standard",
  "metadata": "Standard Tier"
}
```