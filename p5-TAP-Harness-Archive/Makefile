# $NetBSD: Makefile,v 1.3 2009/04/25 17:02:40 athaba Exp $
#

DISTNAME=	TAP-Harness-Archive-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=TAP/}

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://search.cpan.org/dist/TAP-Harness-Archive
COMMENT=	Create an archive of TAP test results

DEPENDS+=	p5-YAML-Tiny>=1.32:../../textproc/p5-YAML-Tiny
DEPENDS+=	p5-Test-Harness>=3.13:../../devel/p5-Test-Harness

PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/TAP/Harness/Archive/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
