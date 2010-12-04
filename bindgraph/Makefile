# $NetBSD: Makefile,v 1.1.1.1 2010/12/04 08:33:13 triaxx Exp $
#

DISTNAME=	bindgraph-0.2
CATEGORIES=	local
MASTER_SITES=	http://www.linux.it/~md/software/
EXTRACT_SUFX=	.tgz

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	http://www.linux.it/~md/software/
COMMENT= Tool that makes graphs from BIND queries
LICENSE= gnu-gpl-v2

DEPENDS+= p5-Time-Local-[0-9]*:../../time/p5-Time-Local

.include "../../databases/rrdtool/buildlink3.mk"

PKG_DESTDIR_SUPPORT= user-destdir

USE_TOOLS+= perl

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+= VARBASE

DBDIR?=	${VARBASE}/db/${PKGBASE}

OWN_DIRS+= ${DBDIR}

BG_SCRIPTS= bindgraph.cgi bindgraph.pl

REPLACE_PERL+= ${BG_SCRIPTS}

RCD_SCRIPTS= bindgraph

SUBST_CLASSES+= defs
SUBST_STAGE.defs=	pre-build
SUBST_FILES.defs=	${BG_SCRIPTS}
SUBST_SED.defs+=	-e "s,'\\.','${DBDIR}',g"
SUBST_SED.defs+=	-e "s,/var/www/as112/rrd,${DBDIR},g"
#
SUBST_MESSAGE.defs=	Fixing defaults.

INSTALLATION_DIRS+=	libexec/cgi-bin
INSTALLATION_DIRS+= share/doc/bindgraph

do-build:

do-configure:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bindgraph.cgi \
		${DESTDIR}${PREFIX}/libexec/cgi-bin/bindgraph.cgi
	${INSTALL_SCRIPT} ${WRKSRC}/bindgraph.pl \
		${DESTDIR}${PREFIX}/sbin/bindgraph
.for i in ChangeLog COPYING README
	${INSTALL_DATA} ${WRKSRC}/${i} \
		${DESTDIR}${PREFIX}/share/doc/bindgraph/${i}
.endfor

.include "../../mk/bsd.pkg.mk"
