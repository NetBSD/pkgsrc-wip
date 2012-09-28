# $NetBSD: Makefile,v 1.6 2012/09/28 22:31:29 asau Exp $
#

DISTNAME=		firehose-0.6.0-src
PKGNAME=	firehose-0.6
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heroines/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://heroinewarrior.com/firehose.php3
COMMENT=		Super fast throughput over cheap ethernet

WRKSRC=		${WRKDIR}/firehose-0.6.0
USE_TOOLS+=gmake

SUBST_CLASSES+=gcc
SUBST_SED.gcc=-e 's,TARGET\ =\ mips,TARGET\ =\ i686,g'
SUBST_FILES.gcc=Makefile
SUBST_STAGE.gcc=configure

INSTALLATION_DIRS=	bin

do-install:
.for f in bottom date* extract fire???? swapon
	${INSTALL_PROGRAM} ${WRKSRC}/i686/${f} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../mk/bsd.pkg.mk"
