# $NetBSD: Makefile,v 1.3 2008/02/05 22:09:14 koifren Exp $

DISTNAME=	mono-1.2.6
CATEGORIES=	lang
MASTER_SITES=	http://go-mono.com/sources/mono/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Open source implementation of the .NET Development Framework

BUILD_DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

CONFLICTS=	pnet-[0-9]*

# XXX please test
NOT_FOR_PLATFORM=	NetBSD-1.[0-5]*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6-* NetBSD-1.6.*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[AB]-*

USE_TOOLS+=		bison gmake gtar perl:run pkg-config bash:run
USE_LIBTOOL=		yes
USE_LANGUAGES+=		c c++
EXTRACT_USING=		gtar

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-icu=yes
CONFIGURE_ARGS+=	--with-preview=yes
CONFIGURE_ARGS+=	--with-libgdiplus=installed

MAKE_FLAGS+=		PERL=${PERL5:Q}
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}
UNLIMIT_RESOURCES=	datasize
UNLIMIT_RESOURCES+=	stacksize
UNLIMIT_RESOURCES+=	memorysize

PKGCONFIG_OVERRIDE+=	data/dotnet.pc.in
PKGCONFIG_OVERRIDE+=	data/mint.pc.in
PKGCONFIG_OVERRIDE+=	data/mono-cairo.pc.in
PKGCONFIG_OVERRIDE+=	mono-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	data/mono.pc.in
PKGCONFIG_OVERRIDE+=	scripts/mono-nunit.pc.in

REPLACE_PERL+=	mcs/errors/do-tests.pl
REPLACE_PERL+=	mcs/tools/scan-tests.pl
REPLACE_PERL+=	msvc/create-windef.pl
REPLACE_PERL+=	mono/benchmark/test-driver
REPLACE_PERL+=	mono/cil/make-opcodes-def.pl
REPLACE_PERL+=	mono/metadata/make-bundle.pl
REPLACE_PERL+=	mono/mini/genmdesc.pl
REPLACE_PERL+=	mono/tests/stress-runner.pl

REPLACE_BASH+=	scripts/mono-find-provides.in
REPLACE_BASH+=	scripts/mono-find-requires.in
REPLACE_BASH+=	mcs/class/Managed.Windows.Forms/build-csproj
REPLACE_BASH+=	mcs/class/Managed.Windows.Forms/build-csproj2k5

EGDIR=		${PREFIX}/share/examples/mono
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/mono/config
CONF_FILES+=	${EGDIR}/browscap.ini ${PKG_SYSCONFDIR}/mono/browscap.ini
CONF_FILES+=	${EGDIR}/1.0/DefaultWsdlHelpGenerator.aspx \
		${PKG_SYSCONFDIR}/mono/1.0/DefaultWsdlHelpGenerator.aspx
CONF_FILES+=	${EGDIR}/1.0/machine.config \
		${PKG_SYSCONFDIR}/mono/1.0/machine.config
CONF_FILES+=	${EGDIR}/2.0/DefaultWsdlHelpGenerator.aspx \
		${PKG_SYSCONFDIR}/mono/2.0/DefaultWsdlHelpGenerator.aspx
CONF_FILES+=	${EGDIR}/2.0/machine.config \
		${PKG_SYSCONFDIR}/mono/2.0/machine.confi

TEST_TARGET=	check

post-patch: substpcprefix
# replace relative prefix in pkgconfig files
substpcprefix:
.for f in ${PKGCONFIG_OVERRIDE}
	(cd ${WRKSRC}; \
	 ${SED} 's|$${pcfiledir}/../..|@prefix@|g' <${f} >${f}.tmp; \
	 ${MV} ${f}.tmp ${f} \
	)
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
