# $NetBSD: Makefile,v 1.1 2013/08/24 13:48:36 outpaddling Exp $

DISTNAME=	v${PORTVERSION}
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

# Doesn't work unless PLIST is correct.  Comment out until pkg is finished.
AUTO_MKDIRS=	yes

do-install:
	# ${MKDIR} ${DESTDIR}${PREFIX}/bin \
		# ${DESTDIR}${PREFIX}/share/bowtie
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

.include "../../mk/bsd.pkg.mk"
