# $NetBSD$

DISTNAME=	Email-Outlook-Message-0.919
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Outlook-Message/
COMMENT=	Read Outlook .msg files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Email-MIME-ContentType>=1.014:../../mail/p5-Email-MIME-ContentType
DEPENDS+=	p5-Email-MIME>=1.923:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-Sender>=1.3:../../mail/p5-Email-Sender
DEPENDS+=	p5-Email-Simple>=2.102:../../mail/p5-Email-Simple
DEPENDS+=	p5-IO-String>=1:../../devel/p5-IO-String
DEPENDS+=	p5-OLE-Storage_Lite>=0.14:../../devel/p5-OLE-Storage_Lite

PERL5_PACKLIST=	auto/Email/Outlook/Message/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
