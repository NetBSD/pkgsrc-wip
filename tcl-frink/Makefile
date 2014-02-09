# $NetBSD: Makefile,v 1.6 2014/02/09 08:40:42 obache Exp $

DISTNAME=	frink-2.2.2p4
CATEGORIES=	devel
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://catless.ncl.ac.uk/Programs/Frink/
COMMENT=	Frink is a tcl formatting and static syntax check program
#LICENSE=	modified-bsd with commercial-exploitaion-exception

RESTRICTED=	For commercial use please contact the author.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

INSTALLATION_DIRS=	bin

WRKSRC=		${WRKDIR}/frink-2.2.2
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
