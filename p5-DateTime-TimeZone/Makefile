# $NetBSD: Makefile,v 1.3 2004/05/10 14:58:13 cubidou Exp $

DISTNAME=	DateTime-TimeZone-0.2601
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-TimeZone/
COMMENT=	Perl module to handle time zone manipulation

DEPENDS+=	p5-Class-Singleton-[0-9]*:../../wip/p5-Class-Singleton
DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build
DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

USE_BUILDLINK3=	YES

.include "../../mk/bsd.prefs.mk"

PERL5_MAN3DIR!=	eval `${PERL5} -V:installsiteman3dir 2>/dev/null`;	\
		${ECHO} $${installsiteman3dir}
PLIST_SUBST+=	PERL5_MAN3DIR=${PERL5_MAN3DIR:S/^${PREFIX}\///}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
