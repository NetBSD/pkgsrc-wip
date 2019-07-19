# $NetBSD$

DISTNAME=	ek16
PKGNAME=	ekermit-${DISTNAME:S/ek//}
CATEGORIES=	comms
MASTER_SITES=	http://www.columbia.edu/kermit/ftp/ek/tar/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://www.columbia.edu/kermit/ek.html
COMMENT=	Implementation of the Kermit file transfer protocol
LICENSE=	modified-bsd

WRKSRC=	${WRKDIR}

MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ek ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
