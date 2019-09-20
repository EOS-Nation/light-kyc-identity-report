const { api, rpc } = require('./eosjs');

(async () => {
  const result = await api.transact({
    actions: [{
      account: 'lightkyciden',
      name: 'add',
      authorization: [{
        actor: 'lightkyciden',
        permission: 'active',
      }],
      data: {
        account: 'deniscarrier',
        key: "EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV",
        tier: 1,
        metadata: "Additional Metadata"
      },
    }]
  }, {
    blocksBehind: 3,
    expireSeconds: 30,
  });
  console.dir(result);
})();
