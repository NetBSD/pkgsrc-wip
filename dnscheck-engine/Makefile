# $NetBSD: Makefile,v 1.8 2010/07/24 19:55:29 pettai Exp $
#

DISTNAME=	dnscheck-${RCVERSION}
PKGNAME=	dnscheck-engine-${RCVERSION:S/-maint//}
CATEGORIES=	net perl5
MASTER_SITES=	# not defined

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://opensource.iis.se/trac/dnscheck/
COMMENT=	DNSCheck is a DNS quality checker
LICENSE=	iis-license

LICENSE_FILE=	${FILESDIR}/iis-license

SVN_REPOSITORIES=	dnscheck
SVN_ROOT.dnscheck=	svn+ssh://anonsvn@opensource.iis.se/dnscheck/branches/${RCVERSION}
SVN_MODULE.dnscheck=	dnscheck
RCVERSION=		1.0-maint
NO_CHECKSUM=		yes

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-Net-DNS>=0.59:../../net/p5-Net-DNS
DEPENDS+=	p5-Net-DNS-SEC>=0.14:../../security/p5-Net-DNS-SEC
DEPENDS+=	p5-Net-IP>=1.25:../../net/p5-Net-IP
DEPENDS+=	p5-TimeDate>=0.19:../../time/p5-TimeDate
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-Socket6>=0.19:../../net/p5-Socket6
DEPENDS+=	p5-IO-Socket-INET6-[0-9]*:../../net/p5-IO-Socket-INET6
DEPENDS+=	p5-Mail-RFC822-Address-[0-9]*:../../mail/p5-Mail-RFC822-Address
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI

PERL5_PACKLIST=	auto/DNSCheck/.packlist
BUILDLINK_API_DEPENDS.perl+=	perl>=5.6.1

#USE_TOOLS+=	perl

WRKSRC=		${WRKDIR}/dnscheck/engine
SYSCONFDIR=	`${BASENAME} ${PKG_SYSCONFDIR}`

BUILD_DEFS+=	IPV6_READY

MAKE_PARAMS+=	CONFIG_DIR="${SYSCONFDIR}"
MAKE_PARAMS+=	POLICY_DIR="${SYSCONFDIR}"
MAKE_PARAMS+=	LOCALE_DIR="${SYSCONFDIR}/locale"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile.PL lib/DNSCheck/Config.pm
SUBST_SED.paths+=	-e s!@SYSCONFDIR@!${SYSCONFDIR}!g

#CONF_FILES=	${EGDIR}/config.yaml ${SYSCONFDIR}/config.yaml
#CONF_FILES+=	${EGDIR}/policy.yaml ${SYSCONFDIR}/policy.yaml
#CONF_FILES+=	${EGDIR}/locale/en.yaml ${SYSCONFDIR}/locale/en.yaml
#CONF_FILES+=	${EGDIR}/locale/sv.yaml ${SYSCONFDIR}/locale/sv.yaml

.include "../../lang/perl5/module.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
