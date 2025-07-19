# bob 14기 sum-nbo

## Usage  

```bash
syntax : sum-nbo <file1> [<file2>...]
sample : sum-nbo a.bin b.bin c.bin

# example
$ make
$ echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
$ echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin
$ echo -n -e \\x00\\x00\\x00\\xc8 > two-hundred.bin
$ ./sum-nbo thousand.bin five-hundred.bin two-hundred.bin
1000(0x000003e8) + 500(0x000001f4) + 200(0x000000c8) = 1700(0x000006a4)
```
## Vedio
https://github.com/user-attachments/assets/3cdc9ea3-ea23-4a45-adaf-1e96b0e42ff0
