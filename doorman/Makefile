# $NetBSD: Makefile,v 1.10 2012/11/25 23:32:09 othyro Exp $
#

DISTNAME=		doorman-0.81
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=doorman/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://doorman.sourceforge.net/
COMMENT=		Open ports when requested by a *secret knock*
LICENSE=		gnu-gpl-v2

DEPENDS=		lsof>4.7:../../sysutils/lsof

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		bison
USE_TOOLS+=		perl
REPLACE_PERL=		ipfw_add ipfw_delete pfctl_add pfctl_delete

INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/doorman
EGDIR=			${PREFIX}/share/examples/doorman
EGFILES=		doormand.cf.EXAMPLE guestlist.EXAMPLE ipchains_add ipchains_delete ipf_add ipf_delete ipfw_add ipfw_delete iptables_add iptables_delete pfctl_add pfctl_delete

.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/doorman/${f}
.endfor

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-patch
SUBST_MESSAGE.fix-paths=	Fixing absolute pathes.
SUBST_FILES.fix-paths=		configure
SUBST_SED.fix-paths=		-e 's,@PREFIX@,${PREFIX},g'

SUBST_CLASSES+=			fix-conf-paths
SUBST_STAGE.fix-conf-paths=	post-configure
SUBST_MESSAGE.fix-conf-paths=	Fixing pathes for configuration files.
SUBST_FILES.fix-conf-paths=	Makefile
SUBST_SED.fix-conf-paths=	-e 's,cfgdir = .*/doormand,cfgdir = ${EGDIR},g'

.include "../../databases/db4/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
