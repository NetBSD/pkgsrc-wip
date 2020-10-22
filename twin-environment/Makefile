# $NetBSD$

# avoid the ambiguous package name 'twin', conflicting with emulators/twin

GITHUB_PROJECT=	twin
DISTNAME=	v0.8.1
PKGNAME=	twin-environment-0.8.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=cosmos72/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cosmos72/twin/
COMMENT=	Text mode window environment
LICENSE=	gnu-gpl-v2.0 AND gnu-lgpl-v2.1

GNU_CONFIGURE=	yes

CPPFLAGS+=	-D_NETBSD_SOURCE

USE_TOOLS+=	bash:runtime

REPLACE_BASH+=	system.twenvrc.sh server/twstart

# Mostly appeasing the interpreter check as the script does not use true.
.if exists(/usr/bin/true)
REPLACE_INTERPRETER+=	true
REPLACE.true.old=	/bin/true
REPLACE.true.new=	/usr/bin/true
REPLACE_FILES.true=	system.twinrc
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
