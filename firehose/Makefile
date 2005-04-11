# $NetBSD: Makefile,v 1.2 2005/04/11 21:12:14 tvierling Exp $
#

DISTNAME=		firehose-0.6.0-src
PKGNAME=	firehose-0.6
CATEGORIES=		wip net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heroines/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://heroinewarrior.com/firehose.php3
COMMENT=		Super fast throughput over cheap ethernet

WRKSRC=		${WRKDIR}/firehose-0.6.0
USE_GNU_TOOLS+=make

SUBST_CLASSES=gcc
SUBST_SED.gcc=-e 's,TARGET\ =\ mips,TARGET\ =\ i686,g'
SUBST_FILES.gcc=Makefile
SUBST_STAGE.gcc=configure

do-install:
.for f in bottom date* extract fire???? swapon
	${INSTALL_PROGRAM} ${WRKSRC}/i686/${f} ${PREFIX}/bin
.endfor

.include "../../mk/bsd.pkg.mk"
