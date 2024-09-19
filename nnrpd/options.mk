# $NetBSD: options.mk,v 1.1 2008/12/15 15:41:19 hfath Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.nnrpd
PKG_SUPPORTED_OPTIONS+=		perl tcl gpg
PKG_SUGGESTED_OPTIONS+=		# none

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mperl)
FILES_SUBST+=		PERL_SUPPORT="DO"

# We need include and library paths to compile in Perl support
PERL_LDOPTS_cmd=	eval ${PERL5} -MExtUtils::Embed -e ldopts 2>/dev/null
PERL_ARCHLIB_cmd=	eval `${PERL5} -V:installarchlib 2>/dev/null`; \
			${ECHO} $${installarchlib}

FILES_SUBST+=		PERL_LDOPTS="${PERL_LDOPTS_cmd:sh}"
FILES_SUBST+=		PERL_INC="-I${PERL_ARCHLIB_cmd:sh}/CORE -DPERL_POLLUTE"
.include "../../lang/perl5/buildlink3.mk"
.else
FILES_SUBST+=		PERL_SUPPORT="DONT"
FILES_SUBST+=		PERL_LDOPTS=""
FILES_SUBST+=		PERL_INC=""
.endif

.if !empty(PKG_OPTIONS:Mtcl)
FILES_SUBST+=		TCL_SUPPORT="DO"
FILES_SUBST+=		TCL_INC="-I${BUILDLINK_PREFIX.tcl}/include"
FILES_SUBST+=		TCL_LIB="-L${BUILDLINK_PREFIX.tcl}/lib -ltcl"
.include "../../lang/tcl/buildlink3.mk"
.else
FILES_SUBST+=		TCL_SUPPORT="DONT"
FILES_SUBST+=		TCL_INC=""
FILES_SUBST+=		TCL_LIB=""
.endif

.if !empty(PKG_OPTIONS:Mgpg)
FILES_SUBST+=		WANT_PGPVERIFY="DO"
DEPENDS+=		gnupg-[0-9]*:../../security/gnupg
.else
FILES_SUBST+=		WANT_PGPVERIFY="DONT"
.endif
