# $NetBSD$

GITHUB_PROJECT=	frida-gum
DISTNAME=	frida-gum-0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=frida/}
GITHUB_TAG=	c41abae2a2b29de3aad7a4fd9daac3e0b150cb54

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.frida.re/
COMMENT=	Low-level code instrumentation library used by frida-core
#LICENSE=	wxwindows library license 3.1 AND modified-bsd AND 2-clause-bsd

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config

PREFER.xz=	pkgsrc # required .pc, missing in NetBSD-base

pre-build:
	${RUN} cd ${WRKSRC}/tests/core && \
		CFLAGS="-fPIC" \
		STRIP=strip \
		CC=${CC} \
		CONFIG_SITE=$PWD \
		PKG_CONFIG=pkg-config \
		LDFLAGS="-fPIC -DPIC" \
		sh build-targetfunctions.sh netbsd x86_64

IGNORE_PKG.glib2=	yes
IGNORE_PKG.libffi=	yes

.include "../../textproc/json-glib/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/capstone/buildlink3.mk"
.include "../../wip/frida-glib2/buildlink3.mk"
.include "../../wip/frida-libffi/buildlink3.mk"
.include "../../devel/py-meson/build.mk"
.include "../../mk/bsd.pkg.mk"
