# $NetBSD: options.mk,v 1.6 2022/05/24 18:25:38 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocaml
PKG_SUPPORTED_OPTIONS=	flambda test
PKG_SUGGESTED_OPTIONS=	flambda test

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mflambda)
CONFIGURE_ARGS+=	--enable-flambda
.else
CONFIGURE_ARGS+=	--disable-flambda
.endif

.if !empty(PKG_OPTIONS:Mtest)
CONFIGURE_ARGS+=	--enable-ocamltest
# test status as of 5.2.0
# List of failed tests:
#    tests/lib-bigarray-2/'bigarrfml.ml' with line 19 (script) PKGSRC-WARNING
#    tests/lib-bigarray-2/'bigarrfml.ml' with line 9 (script) PKGSRC-WARNING
#    tests/lib-systhreads/'testyield.ml' with line 6 (bytecode) Timeout expired, killing all child processes
#    tests/lib-systhreads/'testyield.ml' with line 8 (native) Timeout expired, killing all child processes
#
#Summary:
#  3538 tests passed
#    82 tests skipped
#     4 tests failed
#   148 tests not started (parent test skipped or failed)
#     0 unexpected errors
#  3772 tests considered
.endif
