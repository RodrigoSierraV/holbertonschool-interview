#!/usr/bin/node

const myArgs = process.argv;
const request = require('request');

request(`https://swapi-api.hbtn.io/api/films/${myArgs[2]}`, async (error, response, body) => {
  if (error || response.statusCode !== 200) {
    console.error(error);
    return;
  }
  const characters = JSON.parse(body).characters;
  for (const character of characters) {
    const name = await new Promise((resolve, reject) => {
      request(character, (error1, response1, bodyChar) => {
        if (error1 || response1.statusCode !== 200) {
          reject(error1);
          return;
        }
        resolve(JSON.parse(bodyChar).name);
      });
    });
    console.log(name);
  }
});
