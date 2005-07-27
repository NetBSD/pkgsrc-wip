# $NetBSD: Makefile,v 1.2 2005/07/27 16:30:59 thomasklausner Exp $
#

DISTNAME=		slate-0.2.2
CATEGORIES=		lang
MASTER_SITES=		http://slate.tunes.org/downloads/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://slate.tunes.org/
COMMENT=		Prototype-based object-oriented programming language

BUILD_DEPENDS+=		ecl>=0.9c:../../wip/ecl

WRKSRC=			${WRKDIR}/slate-0-2-2

CONFIGURE_ENV+=		LSPCFLAGS="-I"

do-build:
	cd ${WRKSRC} && \
		${ECHO} ":ld build.lisp" | ${PREFIX}/bin/ecl

.include "../../mk/bsd.pkg.mk"
