# $NetBSD: Makefile,v 1.4 2013/09/01 16:02:54 asau Exp $

DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	bowtie
PKGNAME=	bowtie-${PORTVERSION}
CATEGORIES=	biology
MASTER_SITES=	https://github.com/BenLangmead/bowtie/archive/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://bowtie-bio.sourceforge.net/index.shtml
COMMENT=	Ultrafast, memory-efficient short read aligner

PORTVERSION=	1.0.0
WRKSRC=		${WRKDIR}/${PKGBASE}-${PORTVERSION}

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

# FETCH_ARGS+=	-F
FETCH_USING=	curl

INSTALLATION_DIRS=	bin share/bowtie

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/bowtie \
		${WRKSRC}/bowtie-build \
		${WRKSRC}/bowtie-inspect \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/*.pl \
		${DESTDIR}${PREFIX}/bin
	${CP} -R \
		${WRKSRC}/doc \
		${WRKSRC}/genomes \
		${WRKSRC}/indexes \
		${WRKSRC}/reads \
		${DESTDIR}${PREFIX}/share/bowtie

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
