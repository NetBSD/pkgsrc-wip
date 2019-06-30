# $NetBSD: Makefile,v 1.8 2012/12/04 01:33:25 othyro Exp $
#

DISTNAME=	firehose-0.6.0-src
PKGNAME=	${DISTNAME:S/-src//1}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=heroines/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://heroinewarrior.com/firehose.php
COMMENT=	Super fast throughput over cheap ethernet
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake

SUBST_CLASSES+=		gcc
SUBST_SED.gcc=		-e 's,TARGET\ =\ mips,TARGET\ =\ i686,g'
SUBST_FILES.gcc=	Makefile
SUBST_STAGE.gcc=	pre-configure

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.prefs.mk"

CFLAGS+=		-Dfseeko64=fseeko -Dfopen64=fopen

pre-configure:
	cd ${WRKSRC} && ${MKDIR} i686 mips

do-install:
.for f in bottom date* extract fire???? swapon
	${INSTALL_PROGRAM} ${WRKSRC}/i686/${f} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
