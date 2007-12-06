# $NetBSD: Makefile,v 1.1.1.2 2007/12/06 23:57:07 asau Exp $

DISTNAME=	zabbix-1.4.2
#PKGREVISION=	#
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zabbix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zabbix.com/
COMMENT=	Network monitoring tool

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES
PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

#CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

#EGDIR=			${PREFIX}/share/examples/${PKGNAME}
#CONF_FILES=		${EGDIR}/... ${PKG_SYSCONFDIR}/...

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
