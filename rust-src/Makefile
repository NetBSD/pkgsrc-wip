# $NetBSD$

DISTNAME=	rust-src-1.56.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL:=rust/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rust-lang.org/
COMMENT=	Source for the rust std library
LICENSE=	mit OR apache-2.0

USE_TOOLS+=	bash sh

SRCLIB=			rust-src/lib/rustlib/src/rust/library
REPLACE_BASH+=		install.sh
REPLACE_BASH+=		${SRCLIB}/backtrace/ci/debuglink.sh
REPLACE_BASH+=		${SRCLIB}/stdarch/ci/dox.sh
REPLACE_BASH+=		${SRCLIB}/stdarch/ci/run-docker.sh
REPLACE_BASH+=		${SRCLIB}/stdarch/ci/run.sh
REPLACE_BASH+=		${SRCLIB}/stdarch/ci/style.sh

REPLACE_PYTHON+=	${SRCLIB}/core/src/unicode/printable.py

REPLACE_SH+=		${SRCLIB}/backtrace/ci/android-sdk.sh

NO_INTERPRETER+=	${SRCLIB}/backtrace/ci/android-ndk.sh
NO_INTERPRETER+=	${SRCLIB}/backtrace/ci/debuglink-docker.sh
NO_INTERPRETER+=	${SRCLIB}/backtrace/ci/miri-rustup.sh
NO_INTERPRETER+=	${SRCLIB}/backtrace/ci/run-docker.sh


do-build:
	# These do not have an interpreter line...
	cd ${WRKSRC}; \
	chmod -x ${NO_INTERPRETER}

do-install:
	set -e; \
	\
	cd ${WRKSRC}; \
	env ${MAKE_ENV} \
		${TOOLS_BASH} \
		./install.sh --prefix=${DESTDIR}/${PREFIX};
	# conflicts with main rust package
	rm -f ${DESTDIR}/${PREFIX}/lib/rustlib/components;
	rm -f ${DESTDIR}/${PREFIX}/lib/rustlib/rust-installer-version;
	# fix up install manifest, remove staging ${DESTDIR}
	MANIFEST=${DESTDIR}${PREFIX}/lib/rustlib/manifest-rust-src; \
	${SED} -e 's;file:${DESTDIR};file:;' < $${MANIFEST} > $${MANIFEST}.new; \
	mv $${MANIFEST}.new $${MANIFEST}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
