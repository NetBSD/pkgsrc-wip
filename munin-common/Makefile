# $NetBSD: Makefile,v 1.1 2011/01/09 16:44:04 ftigeot Exp $
#

DISTNAME=	${PKGNAME_NOREV:S:-common-:-:}
PKGNAME=	munin-common-1.4.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=munin/munin%20stable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://munin-monitoring.org/
COMMENT=	Common components between a munin node and master

PKG_DESTDIR_SUPPORT= user-destdir

DEPENDS=	p5-Net-SSLeay>=0:../../security/p5-Net-SSLeay

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	gmake perl:run pax

WRKSRC=				${WRKDIR}/${DISTNAME}/common
PERL5_MODULE_TYPE=	Module::Build

BUILD_DEFS+=	VARBASE

MUNIN_DBDIR=		${VARBASE}/munin
MUNIN_LIBDIR=		${PREFIX}/lib/munin
MUNIN_LOGDIR=		${VARBASE}/log/munin
MUNIN_STATEDIR=		${VARBASE}/run/munin

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	lib/Munin/Common/Defaults.pm
SUBST_VARS.paths=	PKG_SYSCONFDIR MUNIN_DBDIR MUNIN_LIBDIR \
			MUNIN_LOGDIR MUNIN_STATEDIR

post-install:
	cd ${WRKSRC}/blib/libdoc && \
		${PAX} -rw . ${DESTDIR}${PREFIX}/man/man3

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
