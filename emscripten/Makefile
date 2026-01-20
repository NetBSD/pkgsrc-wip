# $NetBSD$

DISTNAME=	4.0.23
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=emscripten-core/}
GITHUB_PROJECT=	emscripten
GITHUB_TAG=	refs/tags/4.0.23
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/emscripten-core/emscripten/
COMMENT=	LLVM-to-WebAssembly Compiler
LICENSE=	mit # or University of Illinois/NCSA Open Source License (requested in license.mk)

WRKSRC=		${WRKDIR}/emscripten-4.0.23
USE_TOOLS+=	pkg-config bash pax
USE_LANGUAGES=	c c++

DEPENDS+=	binaryen-[0-9]*:../../devel/binaryen
DEPENDS+=	llvm-[0-9]*:../../lang/llvm
DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

REPLACE_BASH+=		./system/lib/libcxxabi/src/demangle/cp-to-llvm.sh
REPLACE_NODEJS+=	tools/*.mjs
REPLACE_PYTHON+=	./*.py
REPLACE_PYTHON+=	./site/source/*.py
REPLACE_PYTHON+=	./system/lib/*.py
REPLACE_PYTHON+=	./test/*.py
REPLACE_PYTHON+=	./test/benchmark/*.py
REPLACE_PYTHON+=	./test/third_party/freetype/src/tools/*.py
REPLACE_PYTHON+=	./test/third_party/freetype/src/tools/docmaker/*.py
REPLACE_PYTHON+=	./third_party/ply/example/classcalc/*.py
REPLACE_PYTHON+=	./third_party/ply/example/newclasscalc/*.py
REPLACE_PYTHON+=	./third_party/ply/example/yply/*.py
REPLACE_PYTHON+=	./tools/*.py
REPLACE_PYTHON+=	./tools/maint/*.py
REPLACE_PYTHON+=	./tools/scons/site_scons/site_tools/emscripten/*.py



PKGCONFIG_OVERRIDE+=	test/third_party/bullet/bullet.pc.in
PKGCONFIG_OVERRIDE+=	test/third_party/enet/libenet.pc.in
PKGCONFIG_OVERRIDE+=	test/third_party/freealut/admin/pkgconfig/freealut.pc.in
PKGCONFIG_OVERRIDE+=	test/third_party/openjpeg/libopenjpeg.pc.in
PKGCONFIG_OVERRIDE+=	test/third_party/poppler/poppler-cairo.pc.in
PKGCONFIG_OVERRIDE+=	test/third_party/poppler/poppler-cpp.pc.in
PKGCONFIG_OVERRIDE+=	test/third_party/poppler/poppler-glib.pc.in
PKGCONFIG_OVERRIDE+=	test/third_party/poppler/poppler-qt.pc.in
PKGCONFIG_OVERRIDE+=	test/third_party/poppler/poppler-qt4.pc.in
PKGCONFIG_OVERRIDE+=	test/third_party/poppler/poppler-splash.pc.in
PKGCONFIG_OVERRIDE+=	test/third_party/poppler/poppler.pc.in
PKGCONFIG_OVERRIDE+=	test/third_party/zlib/zlib.pc.in

do-build:

INSTALLATION_DIRS+=	lib/${PKGBASE}

# Borrowed and adopted from FreeBSD port
do-install: # the native install target installs files into root, see https://github.com/emscripten-core/emscripten/issues/17193
	cd ${WRKSRC} && ${PAX} -rw em* cmake site src system third_party tools ${DESTDIR}${PREFIX}/lib/${PKGBASE}/
	${FIND} ${DESTDIR}${PREFIX}/lib/${PKGBASE} \( -name "*.bat" -o -name "*.orig" \) -delete
.for s in ${PYSCRIPTS}
	(${ECHO} "#!/bin/sh"; \
	  ${ECHO} ""; \
	  ${ECHO} "${PYTHON_CMD} ${PREFIX}/lib/${PKGBASE}/${s}.py \"$$"@"\"" \
	) > ${DESTDIR}${PREFIX}/lib/${PKGBASE}/${s}
	${CHMOD} +x ${DESTDIR}${PREFIX}/lib/${PKGBASE}/${s}
	${RLN} ${DESTDIR}${PREFIX}/lib/${PKGBASE}/${s} ${DESTDIR}${PREFIX}/bin/${s}
.endfor
	${CHMOD} -R g-w ${DESTDIR}${PREFIX}/lib/emscripten
	${CHMOD} -x \
		${DESTDIR}${PREFIX}/lib/emscripten/system/lib/libcxx/readme.txt \
		${DESTDIR}${PREFIX}/lib/emscripten/third_party/ply/test/testlex.py


.include "../../lang/nodejs/application.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
