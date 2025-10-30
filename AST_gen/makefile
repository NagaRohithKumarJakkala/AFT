AF_DIR := ../testcases
OUT_DIR := ../generated_asts

AF_FILES := $(wildcard $(AF_DIR)/*.af)
AST_FILES := $(patsubst $(AF_DIR)/%.af, $(OUT_DIR)/%.ast, $(AF_FILES))

test: $(AST_FILES)

$(OUT_DIR)/%.ast: $(AF_DIR)/%.af ../parser/parser.out | $(OUT_DIR)#so that we dont make dir again and again just chekc weather it exists with |
	@../parser/parser.out < $< > $@

$(OUT_DIR):
	@mkdir -p $(OUT_DIR)


clean:
	@rm -rf $(OUT_DIR)
	@echo "removed generated ASTs"
