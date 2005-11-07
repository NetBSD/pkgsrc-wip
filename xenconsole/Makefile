# $NetBSD: Makefile,v 1.3 2005/11/07 14:14:16 marttikuparinen Exp $

PKGNAME=	xenconsole-0.15b1.1
DISTNAME=	xenConsole-r0.15b1-1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ucck/}

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://ucck.sourceforge.net/xenConsole/
COMMENT=	Console monitor for Xen

NO_BUILD=	YES

WRKSRC=		${WRKDIR}/xenConsole

DEPENDS+=	p5-Config-IniFiles>=2.38:../../devel/p5-Config-IniFiles
DEPENDS+=	p5-Curses-UI>=0.95:../../devel/p5-Curses-UI
DEPENDS+=	p5-Curses-UI-POE>=0.02801:../../devel/p5-Curses-UI-POE
DEPENDS+=	p5-Data-Table>=1.43:../../databases/p5-Data-Table
DEPENDS+=	p5-Net-SNMP>=5.0.1:../../net/p5-Net-SNMP
DEPENDS+=	p5-POE>=0.3101:../../devel/p5-POE
DEPENDS+=	p5-POE-Component-SNMP>=0.93:../../net/p5-POE-Component-SNMP
DEPENDS+=	p5-Sys-CpuLoad>=0.03:../../sysutils/p5-Sys-CpuLoad
DEPENDS+=	p5-Term-Size>=0.2:../../devel/p5-Term-Size
DEPENDS+=	p5-Time-HiRes>=0:../../time/p5-Time-HiRes

SUBST_CLASSES+=			xenconsole
SUBST_STAGE.xenconsole=		pre-configure
SUBST_MESSAGE.xenconsole=	"Fixing paths."
SUBST_FILES.xenconsole=		xcon.pl xen_list.pm xsnmp.pm
SUBST_SED.xenconsole=		-e "s,@PERL@,${PERL5},g"
SUBST_SED.xenconsole+=		-e "s,@PREFIX@,${PREFIX},g"

do-install:
	@echo ""
	@echo "Does NOT work yet. Feel free to fix the installation."
	@echo ""
	@${FALSE}

.include "../../mk/bsd.pkg.mk"
