# $NetBSD$

GITHUB_PROJECT=	libseccomp
DISTNAME=	libseccomp-2.5.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=seccomp/}
GITHUB_RELEASE=	v2.5.3

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://github.com/seccomp/libseccomp/
COMMENT=	Interface to the Linux syscall filtering mechanism
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libseccomp.pc.in

.include "../../mk/bsd.pkg.mk"
