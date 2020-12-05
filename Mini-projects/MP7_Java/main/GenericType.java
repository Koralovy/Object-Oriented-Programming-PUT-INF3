package main;

import java.util.*;
import java.lang.*;
import java.io.*;

public class GenericType<T> {

    private T t;

    public T get() {
        return this.t;
    }

    public void set(T t1) {
        this.t = t1;
    }

    public static void main(String args[]) {
        GenericType<String> type = new GenericType<>();
        type.set("PUT");
        System.out.println(type.get());

        GenericType type1 = new GenericType();
        type1.set("UAM");
        System.out.println(type1.get());
        type1.set(10);
        System.out.println(type1.get());

        Checker<Integer> isOddAnonymous = new Checker<Integer>() {
            @Override public boolean check(Integer object) {
                return object % 2 != 0;
            }
        };

        System.out.println(isOddAnonymous.check(123));
        System.out.println(isOddAnonymous.check(124));

        Checker<Integer> isOddLambda = object -> object % 2 != 0;
        System.out.println(isOddLambda.check(123));
        System.out.println(isOddLambda.check(124));
    }
}