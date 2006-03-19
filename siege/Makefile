# $NetBSD: Makefile,v 1.1.1.1 2006/03/19 18:46:27 airhead Exp $
#

DISTNAME=		siege-2.64
CATEGORIES=		www
MASTER_SITES=		ftp://sid.joedog.org/pub/siege/

MAINTAINER=		airhead@users.sf.net
HOMEPAGE=		http://www.joedog.org/siege
COMMENT=		Website/webserver regression testing utility

GNU_CONFIGURE=		yes

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/siege
CONF_FILES=		${EGDIR}/urls.txt \
			${EGDIR}/siegerc

SUBST_CLASSES+=		siege
SUBST_STAGE.siege=	post-patch
SUBST_FILES.siege=	doc/Makefile.am doc/Makefile.in
SUBST_SED.siege+=	-e "s|@EGDIR@|${EGDIR}|g"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
