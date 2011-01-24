# $NetBSD: Makefile,v 1.2 2011/01/24 20:46:41 ftigeot Exp $
#

DISTNAME=	munin-${VERSION}
PKGNAME=	munin-common-${VERSION}
VERSION=	1.4.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=munin/munin%20stable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://munin-monitoring.org/
COMMENT=	Common components between a munin node and master
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT= user-destdir

DEPENDS=	p5-Net-SSLeay>=0:../../security/p5-Net-SSLeay

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	gmake perl:run

WRKSRC=				${WRKDIR}/${DISTNAME}/common
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Munin/Common/.packlist

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

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
