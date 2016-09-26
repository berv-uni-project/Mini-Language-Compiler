# Mini Language Compiler

![Travis Build](https://travis-ci.org/berviantoleo/Mini-Language-Compiler.svg?branch=master)

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
