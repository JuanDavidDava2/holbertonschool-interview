#!/usr/bin/node
const request = require('request');
const arg = process.argv.slice(2);
const ENDPOINT = 'https://swapi-api.hbtn.io/api/films';

if (!arg.length) {
  process.exit(1);
}

request.get(`${ENDPOINT}/${arg}/`, async (error, response, body) => {
  if (error) return console.error(error);

  const chars = JSON.parse(body).characters;
  for (const char of chars) {
    const res = await new Promise((resolve, reject) => request(char, (error, res, body2) => error ? reject(error) : resolve(JSON.parse(body2).name)));
    console.log(res);
  }
});
