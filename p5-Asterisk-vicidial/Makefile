# $NetBSD$

DISTNAME=	asterisk-perl-0.08
PKGNAME=	p5-Asterisk-vicidial-0.08
CATEGORIES=	comms perl5
MASTER_SITES=	http://download.vicidial.com/packages/

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	http://download.vicidial.com/packages/
COMMENT=	Perl modules used with Asterisk-VICIdial
LICENSE=	artistic

PERL5_PACKLSIT=	auto/vicidal/asterisk-perl/.packlist
MAKE_PARAMS+=	PREFIX=${PREFIX}/vicidial/asterisk-perl

# The following  statements were taken from comms/p5-Asterisk Makefile;
EXAMPLES_DIR=		${PREFIX}/share/examples/p5-Asterisk
EXAMPLE_FILES=		agi-enum.agi agi-sayani.agi agi-test.agi
EXAMPLE_FILES+=		calleridnamelookup.agi manager-test.pl
EXAMPLE_FILES+=		tts-bofh.agi tts-line.agi tts-ping.agi

.for file in ${EXAMPLE_FILES}
REPLACE_PERL+=		${WRKSRC}/examples/${file}
.endfor

INSTALLATION_DIRS=	${EXAMPLES_DIR}

post-install:
.for file in ${EXAMPLE_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/${file} ${DESTDIR}${EXAMPLES_DIR}
.endfor

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
