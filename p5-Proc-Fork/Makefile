# $NetBSD: Makefile,v 1.1.1.1 2011/12/07 12:12:23 bubuchka Exp $
#

DISTNAME=	Proc-Fork-0.71
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Proc-Fork/
COMMENT=	Simple, intuitive interface to the fork() system call
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exporter-Tidy-[0-9]*:../../wip/p5-Exporter-Tidy

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Proc/Fork/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
