# $NetBSD: Makefile,v 1.8 2004/02/17 15:16:32 minskim Exp $
#

DISTNAME=		chkrootkit
PKGNAME=		chkrootkit-${VERSION}
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.pangeia.com.br/pub/seg/pac/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.chkrootkit.org/
COMMENT=		Locally checks for signs of a rootkit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/chkrootkit-${VERSION}
VERSION=		0.43
DIST_SUBDIR=		${PKGNAME}
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DSOLARIS2
LDFLAGS+=	-lsocket
.  if empty(CC_VERSION:Mgcc-*)
MAKE_ENV+=	STATIC="-B static"
.  else
MAKE_ENV+=	STATIC="-static"
.  endif
.else
MAKE_ENV+=	STATIC="-static"
.endif

INSTALLATION_DIRS+=	bin

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} chkdirs chklastlog chkproc \
		chkwtmp ifpromisc strings-static ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
