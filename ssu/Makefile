# $NetBSD: Makefile,v 1.1.1.1 2006/12/24 08:30:43 thomasklausner Exp $
#

DISTNAME=	ssu-0.8
CATEGORIES=	devel
MASTER_SITES=	http://www.yuv.info/~wavexx/hacks/ssu/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yuv.info/~wavexx/hacks/ssu/
COMMENT=	Command-line access to local and remote Source Safe/VSS repositories

DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5

REPLACE_PERL=	ss ssserv
USE_LANGUAGES=	# none
USE_TOOLS+=	perl

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ss ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ssserv ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ssu
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ssu

.include "../../mk/bsd.pkg.mk"
