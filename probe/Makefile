# $NetBSD: Makefile,v 1.2 2010/04/18 14:30:16 jihbed Exp $
#

DISTNAME=	probe-1.30-linux6
PKGNAME=	${DISTNAME:S/-linux6//}
CATEGORIES=	devel
MASTER_SITES=	http://www.fsel.com/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.fsel.com/software.html
COMMENT=	ProBE is an animator for CSP processes

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base x11


PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	bin share/doc/probe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/probe ${DESTDIR}${PREFIX}/bin/probe
	${INSTALL_DATA} ${WRKSRC}/Licence ${DESTDIR}${PREFIX}/share/doc/probe
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/probe

.include "../../mk/bsd.pkg.mk"
