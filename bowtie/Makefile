# $NetBSD: Makefile,v 1.8 2014/06/01 12:49:35 thomasklausner Exp $

DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	bowtie
PKGNAME=	bowtie-${PORTVERSION}
CATEGORIES=	biology
MASTER_SITES=	https://github.com/BenLangmead/bowtie/archive/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://bowtie-bio.sourceforge.net/index.shtml
COMMENT=	Ultrafast, memory-efficient short read aligner

PORTVERSION=	1.0.0
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake perl:run

# FETCH_ARGS+=	-F

INSTALLATION_DIRS=	bin share/bowtie

REPLACE_PERL=	scripts/*.pl scripts/test/*.pl doc/*.pl

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} bowtie bowtie-build bowtie-inspect \
		${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_SCRIPT} scripts/*.sh scripts/*.pl \
		${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${CP} -R doc genomes indexes reads \
		${DESTDIR}${PREFIX}/share/bowtie

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
