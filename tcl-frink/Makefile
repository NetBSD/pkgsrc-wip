# $NetBSD: Makefile,v 1.1 2014/01/17 13:38:26 keckhardt Exp $

DISTNAME=	frink-2.2.2p4
PKGNAME=	tcl-frink-2.2.2p4
CATEGORIES=	lang
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://catless.ncl.ac.uk/Programs/Frink/
COMMENT=	Frink is a tcl formatting and static syntax check program
LICENSE=	modified-bsd
RESTRICTED=	For commercial use please contact the author.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

WRKSRC=		${WRKDIR}/frink-2.2.2
GNU_CONFIGURE=	yes

AUTO_MKDIRS=	yes

do-install:
	${CP} ${WRKSRC}/frink ${DESTDIR}${PREFIX}/bin


.include "../../mk/bsd.pkg.mk"
