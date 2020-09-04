# $NetBSD: Makefile,v 1.12 2012/10/07 16:22:55 asau Exp $

DISTNAME=	ptksdict-1.2.1
PKGNAME=	${DISTNAME:S/ptksdict/sdict-tools/}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://sdict.com/rsc/files/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://sdict.com/
COMMENT=	SDict conversion tools

USE_TOOLS+=		gzip tar

DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-Crypt-Blowfish-[0-9]*:../../security/p5-Crypt-Blowfish
DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk
DEPENDS+=	p5-IO-Compress-[0-9]*:../../devel/p5-IO-Compress
#DEPENDS+=	p5-IO-File-[0-9]*:../../devel/p5-IO-File
DEPENDS+=	p5-IO-All-[0-9]*:../../devel/p5-IO-All
DEPENDS+=	p5-Getopt-Long-[0-9]*:../../devel/p5-Getopt-Long
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump

NO_BUILD=	yes

REPLACE_PERL+=	bin/sdict-tools.plx
REPLACE_PERL+=	bin/ptksdict.plx
REPLACE_PERL+=	bin/sdict.plx
REPLACE_PERL+=	bin/jotter.plx
REPLACE_PERL+=	bin/data.plx
REPLACE_PERL+=	bin/dctinfo.plx

SDICT_BINDIR=		${PREFIX}/ptksdict/bin
SDICT_LIBDIR=		${PREFIX}/ptksdict/bin

INSTALLATION_DIRS=	${SDICT_LIBDIR} ${SDICT_BINDIR}

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	# none

do-extract:
	set -e; \
	mkdir ${WRKSRC}; \
	cd ${WRKSRC}; \
	gzip -d ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}; \
	tar -xf ${DISTDIR}/${DISTNAME}.tar

do-install:
	set -e; \
	cd ${WRKSRC}; \
	${INSTALL_SCRIPT} bin/sdict-tools.plx ${DESTDIR}${SDICT_BINDIR}; \
	${INSTALL_DATA} lib/Sdict.pm ${DESTDIR}${SDICT_LIBDIR}

.include "../../mk/bsd.pkg.mk"
