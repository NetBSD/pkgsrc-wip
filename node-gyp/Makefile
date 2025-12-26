# $NetBSD$

DISTNAME=	node-gyp-12.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nodejs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTFILES=	${DEFAULT_DISTFILES} node-gyp-12.1.0-dependencies.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nodejs/node-gyp/
COMMENT=	Node.js native addon build tool
LICENSE=	mit

USE_LANGUAGES=	c c++

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	gyp/*.py
REPLACE_PYTHON+=	gyp/pylib/gyp/*.py
REPLACE_PYTHON+=	gyp/pylib/gyp/generator/*.py
REPLACE_PYTHON+=	gyp/pylib/packaging/*.py
REPLACE_PYTHON+=	gyp/tools/*.py
REPLACE_PYTHON+=	test/fixtures/*.py

REPLACE_NODE+=	bin/node-gyp.js
REPLACE_NODE+=	node_modules/acorn/bin/acorn
REPLACE_NODE+=	node_modules/cross-env/dist/bin/cross-env-shell.js
REPLACE_NODE+=	node_modules/cross-env/dist/bin/cross-env.js
REPLACE_NODE+=	node_modules/cross-spawn/node_modules/which/bin/node-which
REPLACE_NODE+=	node_modules/eslint-plugin-react/node_modules/semver/bin/semver.js
REPLACE_NODE+=	node_modules/eslint/bin/eslint.js
REPLACE_NODE+=	node_modules/flat/cli.js
REPLACE_NODE+=	node_modules/he/bin/he
REPLACE_NODE+=	node_modules/js-yaml/bin/js-yaml.js
REPLACE_NODE+=	node_modules/loose-envify/cli.js
REPLACE_NODE+=	node_modules/mocha/bin/_mocha
REPLACE_NODE+=	node_modules/mocha/bin/mocha.js
REPLACE_NODE+=	node_modules/mocha/node_modules/glob/dist/esm/bin.mjs
REPLACE_NODE+=	node_modules/nan/tools/1to2.js
REPLACE_NODE+=	node_modules/napi-postinstall/lib/cli.js
REPLACE_NODE+=	node_modules/neostandard/cli.mjs
REPLACE_NODE+=	node_modules/nopt/bin/nopt.js
REPLACE_NODE+=	node_modules/resolve/bin/resolve
REPLACE_NODE+=	node_modules/semver/bin/semver.js
REPLACE_NODE+=	node_modules/typescript/bin/tsc
REPLACE_NODE+=	node_modules/typescript/bin/tsserver
REPLACE_NODE+=	node_modules/which/bin/which.js

.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../wip/prettier/npm.mk"
.include "../../mk/bsd.pkg.mk"
