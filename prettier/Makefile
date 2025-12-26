# $NetBSD$

DISTNAME=	prettier-3.7.4
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=prettier/}
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTFILES=	${DEFAULT_DISTFILES} prettier-3.7.4-dependencies.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/prettier/prettier/
COMMENT=	Opinionated JavaScript code formatter
LICENSE=	mit

USE_LANGUAGES=	# none

CHECK_INTERPRETER_SKIP+=	lib/node_modules/prettier/node_modules/.bin/knip-bun
CHECK_INTERPRETER_SKIP+=	lib/node_modules/prettier/node_modules/exit-x/test/fixtures/create-files.sh
CHECK_INTERPRETER_SKIP+=	lib/node_modules/prettier/node_modules/knip/bin/knip-bun.js
CHECK_INTERPRETER_SKIP+=	lib/node_modules/prettier/node_modules/shell-quote/print.py
CHECK_INTERPRETER_SKIP+=	lib/node_modules/prettier/scripts/benchmark/compare.sh

REPLACE_NODE+=	bin/prettier.cjs
REPLACE_NODE+=	bin/prettier.js
REPLACE_NODE+=	node_modules/@babel/core/node_modules/@babel/parser/bin/babel-parser.js
REPLACE_NODE+=	node_modules/@babel/core/node_modules/semver/bin/semver.js
REPLACE_NODE+=	node_modules/@babel/helper-compilation-targets/node_modules/semver/bin/semver.js
REPLACE_NODE+=	node_modules/@babel/parser/bin/babel-parser.js
REPLACE_NODE+=	node_modules/@babel/template/node_modules/@babel/parser/bin/babel-parser.js
REPLACE_NODE+=	node_modules/@babel/traverse/node_modules/@babel/parser/bin/babel-parser.js
REPLACE_NODE+=	node_modules/@istanbuljs/load-nyc-config/node_modules/js-yaml/bin/js-yaml.js
REPLACE_NODE+=	node_modules/@prettier/cli/dist/bin.d.ts
REPLACE_NODE+=	node_modules/@prettier/cli/dist/bin.js
REPLACE_NODE+=	node_modules/@types/babel__core/node_modules/@babel/parser/bin/babel-parser.js
REPLACE_NODE+=	node_modules/@types/babel__template/node_modules/@babel/parser/bin/babel-parser.js
REPLACE_NODE+=	node_modules/acorn/bin/acorn
REPLACE_NODE+=	node_modules/ajv/scripts/info
REPLACE_NODE+=	node_modules/babel-plugin-istanbul/lib/load-nyc-config-sync.js
REPLACE_NODE+=	node_modules/baseline-browser-mapping/dist/cli.js
REPLACE_NODE+=	node_modules/browserslist-to-esbuild/cli/index.js
REPLACE_NODE+=	node_modules/browserslist/cli.js
REPLACE_NODE+=	node_modules/c8/bin/c8.js
REPLACE_NODE+=	node_modules/cross-env/dist/bin/cross-env-shell.d.ts
REPLACE_NODE+=	node_modules/cross-env/dist/bin/cross-env-shell.js
REPLACE_NODE+=	node_modules/cross-env/dist/bin/cross-env.d.ts
REPLACE_NODE+=	node_modules/cross-env/dist/bin/cross-env.js
REPLACE_NODE+=	node_modules/cspell-config-lib/node_modules/yaml/bin.mjs
REPLACE_NODE+=	node_modules/cspell-gitignore/bin.mjs
REPLACE_NODE+=	node_modules/cspell-grammar/bin.mjs
REPLACE_NODE+=	node_modules/cspell/bin.mjs
REPLACE_NODE+=	node_modules/editorconfig/bin/editorconfig
REPLACE_NODE+=	node_modules/editorconfig/node_modules/semver/bin/semver
REPLACE_NODE+=	node_modules/esbuild-visualizer/dist/bin/cli.d.ts
REPLACE_NODE+=	node_modules/esbuild-visualizer/dist/bin/cli.js
REPLACE_NODE+=	node_modules/esbuild/install.js
REPLACE_NODE+=	node_modules/eslint-config-prettier/bin/cli.js
REPLACE_NODE+=	node_modules/eslint/bin/eslint.js
REPLACE_NODE+=	node_modules/esprima/bin/esparse.js
REPLACE_NODE+=	node_modules/esprima/bin/esvalidate.js
REPLACE_NODE+=	node_modules/find-in-directory/readme.md
REPLACE_NODE+=	node_modules/formatly/bin/index.mjs
REPLACE_NODE+=	node_modules/glob/dist/esm/bin.d.mts
REPLACE_NODE+=	node_modules/glob/dist/esm/bin.mjs
REPLACE_NODE+=	node_modules/glob/dist/esm/bin.mjs.map
REPLACE_NODE+=	node_modules/import-local/fixtures/cli.js
REPLACE_NODE+=	node_modules/is-docker/cli.js
REPLACE_NODE+=	node_modules/is-inside-container/cli.js
REPLACE_NODE+=	node_modules/is-inside-container/node_modules/is-docker/cli.js
REPLACE_NODE+=	node_modules/istanbul-lib-instrument/node_modules/@babel/parser/bin/babel-parser.js
REPLACE_NODE+=	node_modules/jest-cli/bin/jest.js
REPLACE_NODE+=	node_modules/jest-snapshot/node_modules/@babel/parser/bin/babel-parser.js
REPLACE_NODE+=	node_modules/jest/bin/jest.js
REPLACE_NODE+=	node_modules/jiti/lib/jiti-cli.mjs
REPLACE_NODE+=	node_modules/js-yaml/bin/js-yaml.js
REPLACE_NODE+=	node_modules/jsesc/bin/jsesc
REPLACE_NODE+=	node_modules/json5/lib/cli.js
REPLACE_NODE+=	node_modules/knip/bin/knip.js
REPLACE_NODE+=	node_modules/knip/dist/typescript/visitors/scripts/zx.js
REPLACE_NODE+=	node_modules/meow/build/index.d.ts
REPLACE_NODE+=	node_modules/meow/readme.md
REPLACE_NODE+=	node_modules/nanoid/bin/nanoid.cjs
REPLACE_NODE+=	node_modules/napi-postinstall/lib/cli.d.ts
REPLACE_NODE+=	node_modules/napi-postinstall/lib/cli.js
REPLACE_NODE+=	node_modules/npm-run-all2/bin/npm-run-all/index.js
REPLACE_NODE+=	node_modules/npm-run-all2/bin/run-p/index.js
REPLACE_NODE+=	node_modules/npm-run-all2/bin/run-s/index.js
REPLACE_NODE+=	node_modules/npm-run-all2/node_modules/which/bin/which.js
REPLACE_NODE+=	node_modules/pidtree/bin/pidtree.js
REPLACE_NODE+=	node_modules/prettier/bin/prettier.cjs
REPLACE_NODE+=	node_modules/regexp-tree/bin/regexp-tree
REPLACE_NODE+=	node_modules/regjsparser/bin/parser
REPLACE_NODE+=	node_modules/rollup/dist/bin/rollup
REPLACE_NODE+=	node_modules/semver/bin/semver.js
REPLACE_NODE+=	node_modules/shebang-command/readme.md
REPLACE_NODE+=	node_modules/shebang-regex/index.d.ts
REPLACE_NODE+=	node_modules/shebang-regex/readme.md
REPLACE_NODE+=	node_modules/specialist/readme.md
REPLACE_NODE+=	node_modules/typescript/bin/tsc
REPLACE_NODE+=	node_modules/typescript/bin/tsserver
REPLACE_NODE+=	node_modules/update-browserslist-db/cli.js
REPLACE_NODE+=	node_modules/which/bin/node-which
REPLACE_NODE+=	scripts/generate-changelog.js

.include "npm.mk"
.include "../../mk/bsd.pkg.mk"
