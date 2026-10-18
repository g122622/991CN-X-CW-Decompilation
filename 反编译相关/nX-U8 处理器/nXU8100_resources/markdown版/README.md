# nX-U8100 手册的 Markdown 版

本目录的 `nX-U8100 Core Instruction Manual.md` 是把
`../nX-U8100 Core Instruction Manual.pdf`（nX-U8/100 Core Instruction Manual，
OKI，FEZ0317A0-U8-INST-02）用 [MinerU](https://mineru.net) 的 `flash-extract`
分段解析后合并得到的。

- 分段：PDF 超过 MinerU 免费模式 20 页上限，按 1-20 / 21-40 / 41-60 / 61-80 四段解析，
  文中以 `<!-- ===== PDF 第 a-b 页 ===== -->` 分隔；
- 表格/图以 OCR 结果保留，个别寄存器位图可能有乱码，原意以 PDF 为准；
- 可用于 grep 查找指令语义（`DAA`、`BC`、`PSW`、`ROM window`、`DSR` 等），
  再回到 PDF 的对应页核对。

重新生成（需要 `mineru-open-api`）：

```bash
PDF="../nX-U8100 Core Instruction Manual.pdf"
for r in 1-20 21-40 41-60 61-80; do
  mineru-open-api flash-extract "$PDF" --pages $r > "part_$r.md"
done
```

其余芯片文档（`../../chipset_docs/`）尚未解析；需要时按同样方式处理。