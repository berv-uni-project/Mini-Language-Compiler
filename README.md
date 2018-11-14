# Mini Language Compiler

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/1321d95bf070444cbad71c39cb2987df)](https://app.codacy.com/app/berviantoleo/Mini-Language-Compiler?utm_source=github.com&utm_medium=referral&utm_content=berv-uni-project/Mini-Language-Compiler&utm_campaign=Badge_Grade_Settings)
[![Build Status](https://travis-ci.org/berv-uni-project/Mini-Language-Compiler.svg?branch=master)](https://travis-ci.org/berv-uni-project/Mini-Language-Compiler)

Learning to parsing and to be mini compiler for small language

### Run executable code compiler.exe with command prompt.

### Membuat input :
  * (edit file "program.txt")
  * Isi program yang ingin dites.

### Contoh isi diterima:

```pascal
begin
  input(z) {menerima masukan z berupa nilai integer}
  do
    if (z<10) then
    begin
      a=z*2
      output(a)
    end
    else
    begin
      output(z*10)
    end
    input(z)
  while (z < 999)
end
```

### Contoh tidak diterima : 

    jika end dihilangkan
