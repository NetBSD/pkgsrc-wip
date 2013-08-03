# $NetBSD: Makefile,v 1.9 2013/08/03 20:58:23 kristerw Exp $
#

DISTNAME=	Siesta-0.66
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RC/RCLAMP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://siesta.unixbeard.net/
COMMENT=	Siesta Mailing List Manager
LICENSE=	${PERL5_LICENSE}

#BROKEN=		"Configure script needs special handling."

DEPENDS+=	p5-Apache-Session-SharedMem-[0-9]*:../../www/p5-Apache-Session-SharedMem
DEPENDS+=	p5-Class-DBI-[0-9]*:../../databases/p5-Class-DBI
DEPENDS+=	p5-Class-DBI-BaseDSN-[0-9]*:../../databases/p5-Class-DBI-BaseDSN
DEPENDS+=	p5-Class-DBI-SQLite-[0-9]*:../../wip/p5-Class-DBI-SQLite
DEPENDS+=	p5-Email-Folder-[0-9]*:../../mail/p5-Email-Folder
DEPENDS+=	p5-Email-LocalDelivery>=0.05:../../mail/p5-Email-LocalDelivery
DEPENDS+=	p5-Email-Simple>=1.4:../../mail/p5-Email-Simple
DEPENDS+=	p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-Mail-DeliveryStatus-BounceParser-[0-9]*:../../mail/p5-Mail-DeliveryStatus-BounceParser
DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build
DEPENDS+=	p5-Python-Serialise-Marshal-[0-9]*:../../devel/p5-Python-Serialise-Marshal
DEPENDS+=	p5-String-Random-[0-9]*:../../security/p5-String-Random
DEPENDS+=	p5-String-ShellQuote-[0-9]*:../../textproc/p5-String-ShellQuote
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-accessors-fast-[0-9]*:../../devel/p5-accessors-fast

PERL5_MODULE_TYPE=	Module::Build
USE_TOOLS+=		perl:run

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	Build.PL
SUBST_MESSAGE.prefix=	Fixing PREFIX.
SUBST_SED.prefix=	-e "s|/usr/local/siesta|${PREFIX}|1"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
