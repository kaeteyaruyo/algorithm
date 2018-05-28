const N = 10;
const T = [7,1,4,2,8,3,5,9,10,6];
const M = [9,4,6,3,2,10,4,7,5,1];
const Pt = [], Pm = [], Ct = [], Cm = [];
const candy = [];
let St = 0, Sm = 0, answer = 0;

for(let i = 0; i < N; ++i){
  candy.push(false);
  Pt.push({candy: i, prefer: T[i] - M[i]});
  Pm.push({candy: i, prefer: M[i] - T[i]});
}

Pt.sort((a, b) => (b.prefer - a.prefer !== 0) ? (b.prefer - a.prefer) : (T[b.candy] - T[a.candy]));
Pm.sort((a, b) => (b.prefer - a.prefer !== 0) ? (b.prefer - a.prefer) : (M[b.candy] - M[a.candy]));

let j = 0, k = 0;
for(let i = 1; i <= Math.floor(N / 2); ++i){
  while(candy[Pt[j].candy]) ++j;
  candy[Pt[j].candy] = true;
  St += T[Pt[j].candy];
  Ct.push(T[Pt[j].candy]);

  while(candy[Pm[k].candy]) ++k;
  Sm += M[Pm[k].candy];
  candy[Pm[k].candy] = true;
  Cm.push(M[Pm[k].candy]);
}

if(N % 2 === 1){
  let forTom = Math.abs((St + T[candy.indexOf(false)]) - Sm);
  let forMark = Math.abs((Sm + M[candy.indexOf(false)]) - St);
  if(forTom < forMark){
    answer = forTom;
    Ct.push(T[candy.indexOf(false)]);
  }
  else{
    answer = forMark;
    Cm.push(M[candy.indexOf(false)]);
  }
}
else answer = Math.abs(St - Sm);

console.log(Ct);
console.log(Cm);
console.log(answer);
