# $NetBSD: Makefile,v 1.3 2006/08/27 17:57:44 airhead Exp $
#

DISTNAME=		siege-2.65
CATEGORIES=		www
MASTER_SITES=		ftp://sid.joedog.org/pub/siege/

MAINTAINER=		airhead@users.sf.net
HOMEPAGE=		http://www.joedog.org/JoeDog/Siege
COMMENT=		Website/webserver regression testing utility

GNU_CONFIGURE=		yes

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/siege
CONF_FILES=		${EGDIR}/urls.txt ${PKG_SYSCONFDIR}/urls.txt

SUBST_CLASSES+=		siege
SUBST_STAGE.siege=	post-patch
SUBST_FILES.siege=	doc/Makefile.am doc/Makefile.in
SUBST_SED.siege+=	-e "s|@EGDIR@|${EGDIR}|g"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
